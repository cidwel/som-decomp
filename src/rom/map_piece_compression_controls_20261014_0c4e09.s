.setcpu "65816"
.segment "CODE"
.org $4E09
map_control_0c4e09:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
