.setcpu "65816"
.segment "CODE"
.org $EB7C
.a8
compare_party_noop_selector:
    cmp #$05
    bcs $EBAF
