; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16

request_native_menu_audio_0e = $D0CF08

.segment "CODE"
.org $7AB5
dispatch_native_shop_action_to_buy_sell_or_weapon_upgrade:
    jsl f:request_native_menu_audio_0e
    sep #$30
    .a8
    lda #$40
    tsb a:$1804
    lda a:$1847
    dec
    asl
    tax
    rep #$30
    jmp ($7ACB,X)
