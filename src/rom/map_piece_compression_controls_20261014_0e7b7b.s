.setcpu "65816"
.segment "CODE"
.org $7B7B
map_control_0e7b7b:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
