; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-state-api.md.
.setcpu "65816"
.smart
.a8
.i16

dim_palette_request_upload_and_await_real_menu_vblank = $D0CD2A
normalize_menu_native_direct_page_and_bank = $C064A4
restore_inventory_menu_direct_page_bank_and_status = $645C

.segment "CODE"
.org $6460
dim_existing_native_menu_palette_with_saved_context:
    php
    phb
    phd
    jsl f:normalize_menu_native_direct_page_and_bank
    sep #$20
    .a8
    lda #$01
    tsb a:$1803
    jsl f:dim_palette_request_upload_and_await_real_menu_vblank
    bra restore_inventory_menu_direct_page_bank_and_status
