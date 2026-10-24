.setcpu "65816"
.segment "CODE"
.org $037A
map_control_0e037a:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E1 ; previous-row copy count
