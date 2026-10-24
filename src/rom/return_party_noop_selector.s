.setcpu "65816"
.segment "CODE"
.org $EBAF
return_party_noop_selector:
    bne $EBB2
    rts
