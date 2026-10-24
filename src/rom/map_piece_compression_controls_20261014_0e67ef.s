.setcpu "65816"
.segment "CODE"
.org $67EF
map_control_0e67ef:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E5 ; previous-row copy count
