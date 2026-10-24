.setcpu "65816"
.segment "CODE"
.org $EFF2
map_control_0deff2:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
