.setcpu "65816"
.segment "CODE"
.org $591D
map_control_0f591d:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E7 ; previous-row copy count
