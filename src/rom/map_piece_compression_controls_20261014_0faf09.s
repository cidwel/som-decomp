.setcpu "65816"
.segment "CODE"
.org $AF09
map_control_0faf09:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E5 ; previous-row copy count
