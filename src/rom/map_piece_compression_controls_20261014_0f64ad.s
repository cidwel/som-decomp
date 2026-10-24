.setcpu "65816"
.segment "CODE"
.org $64AD
map_control_0f64ad:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
