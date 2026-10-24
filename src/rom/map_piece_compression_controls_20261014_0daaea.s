.setcpu "65816"
.segment "CODE"
.org $AAEA
map_control_0daaea:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E2 ; previous-row copy count
