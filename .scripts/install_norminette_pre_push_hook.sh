#!/bin/bash
set -e

ROOT_DIR=$(git rev-parse --show-toplevel)
HOOKS_DIR="$ROOT_DIR/.git/hooks"

echo "Creating norminette pre-push hook..."
cat > "$HOOKS_DIR/pre-push" << 'EOF'
#!/bin/sh
# Pre-push hook

echo "Running norminette..."
norminette || exit 1
EOF
chmod +x "$HOOKS_DIR/pre-push"

echo "Norminette pre-push hook installed successfully"
