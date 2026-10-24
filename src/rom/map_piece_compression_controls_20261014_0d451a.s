.setcpu "65816"
.segment "CODE"
.org $451A
map_control_0d451a:
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
