.setcpu "65816"
.segment "CODE"
.org $BAB1
map_control_0fbab1:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
