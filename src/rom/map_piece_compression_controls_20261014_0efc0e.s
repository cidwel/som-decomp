.setcpu "65816"
.segment "CODE"
.org $FC0E
map_control_0efc0e:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
