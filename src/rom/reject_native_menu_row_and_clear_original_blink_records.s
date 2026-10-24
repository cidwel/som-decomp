; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-transaction-finish.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_ring_blink_bit_in_twelve_rows = $7908
finish_native_menu_transaction_and_request_loop_refresh = $760A
request_native_menu_audio_0d = $D0CF00

.segment "CODE"
.org $7594
reject_native_menu_row_and_clear_original_blink_records:
    jsl f:request_native_menu_audio_0d
    jsr clear_native_menu_ring_blink_bit_in_twelve_rows
    jmp finish_native_menu_transaction_and_request_loop_refresh
