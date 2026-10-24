.setcpu "65816"
.segment "CODE"
.org $367A
map_control_0d367a:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E4 ; previous-row copy count
