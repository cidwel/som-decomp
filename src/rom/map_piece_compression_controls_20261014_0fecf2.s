.setcpu "65816"
.segment "CODE"
.org $ECF2
map_control_0fecf2:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
