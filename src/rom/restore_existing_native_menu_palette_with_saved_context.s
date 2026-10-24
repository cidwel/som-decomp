; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-state-api.md.
.setcpu "65816"
.smart
.a8
.i16

normalize_menu_native_direct_page_and_bank = $C064A4
restore_inventory_menu_direct_page_bank_and_status = $645C
restore_saved_menu_palette_and_request_upload = $D0CD6D

.segment "CODE"
.org $6474
restore_existing_native_menu_palette_with_saved_context:
    php
    phb
    phd
    jsl f:normalize_menu_native_direct_page_and_bank
    jsl f:restore_saved_menu_palette_and_request_upload
    bra restore_inventory_menu_direct_page_bank_and_status
