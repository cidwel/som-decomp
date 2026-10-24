.setcpu "65816"
.segment "CODE"
.org $E519
map_control_0fe519:
    .byte $D6 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E4 ; previous-row copy count
