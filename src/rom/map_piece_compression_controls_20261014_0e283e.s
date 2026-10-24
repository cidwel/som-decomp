.setcpu "65816"
.segment "CODE"
.org $283E
map_control_0e283e:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E1 ; previous-row copy count
