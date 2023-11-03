<?php


define( 'DB_NAME', 'wordpress');
define( 'DB_USER', 'suchy');
define( 'DB_PASSWORD', '42prague');
define( 'DB_HOST', 'mariadb' );
define( 'DB_CHARSET', 'utf8');
define( 'DB_COLLATE', '');

define('AUTH_KEY',         '4');
define('SECURE_AUTH_KEY',  '2');
define('LOGGED_IN_KEY',    'P');
define('NONCE_KEY',        'R');
define('AUTH_SALT',        'A');
define('SECURE_AUTH_SALT', 'G');
define('LOGGED_IN_SALT',   'U');
define('NONCE_SALT',       'E');

$table_prefix = 'wp_';

define( 'WP_DEBUG', false);

if ( !defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', '/var/www/html/wordpress' );
}

require_once ABSPATH . 'wp-settings.php';

?>