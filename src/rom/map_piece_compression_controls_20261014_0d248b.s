.setcpu "65816"
.segment "CODE"
.org $248B
map_control_0d248b:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E3 ; previous-row copy count
