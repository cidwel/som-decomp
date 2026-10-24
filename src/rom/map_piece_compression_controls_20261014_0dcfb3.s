.setcpu "65816"
.segment "CODE"
.org $CFB3
map_control_0dcfb3:
    .byte $E4 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2B ; distance low bit/count
    .byte $E4 ; previous-row copy count
