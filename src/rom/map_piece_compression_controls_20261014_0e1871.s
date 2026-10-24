.setcpu "65816"
.segment "CODE"
.org $1871
map_control_0e1871:
    .byte $EB ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
