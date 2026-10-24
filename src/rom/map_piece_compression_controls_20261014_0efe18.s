.setcpu "65816"
.segment "CODE"
.org $FE18
map_control_0efe18:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
