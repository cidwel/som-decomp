.setcpu "65816"
.segment "CODE"
.org $F59C
map_control_0ff59c:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
