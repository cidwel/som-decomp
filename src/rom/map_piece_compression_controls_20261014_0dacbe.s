.setcpu "65816"
.segment "CODE"
.org $ACBE
map_control_0dacbe:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
