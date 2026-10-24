; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

test_map_object_creation_eligibility_and_dispatch = $DDE3

.segment "CODE"
.org $DDBE
scan_map_object_cache_for_creation:
scan_map_object_cache_for_creation_c0ddbe:
    sep #$20
    lda a:$C800,Y
    beq scan_map_object_cache_for_creation_c0ddcd
    bmi scan_map_object_cache_for_creation_c0ddcf
    jsr test_map_object_creation_eligibility_and_dispatch
    bcc scan_map_object_cache_for_creation_c0ddcf
    rts
scan_map_object_cache_for_creation_c0ddcd:
    clc
    rts
scan_map_object_cache_for_creation_c0ddcf:
    sep #$20
    dec $0C
    beq scan_map_object_cache_for_creation_c0ddcd
    rep #$20
    tya
    clc
    .a16
    adc #$0010
    tay
    .a16
    cmp #$0300
    bcc scan_map_object_cache_for_creation_c0ddbe
    rts
