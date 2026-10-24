.setcpu "65816"
.segment "CODE"
.org $356A
map_control_0f356a:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E1 ; previous-row copy count
