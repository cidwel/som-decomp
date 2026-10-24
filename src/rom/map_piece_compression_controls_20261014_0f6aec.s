.setcpu "65816"
.segment "CODE"
.org $6AEC
map_control_0f6aec:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
