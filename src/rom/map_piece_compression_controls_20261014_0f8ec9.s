.setcpu "65816"
.segment "CODE"
.org $8EC9
map_control_0f8ec9:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E1 ; previous-row copy count
