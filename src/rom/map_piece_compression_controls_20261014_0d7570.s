.setcpu "65816"
.segment "CODE"
.org $7570
map_control_0d7570:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $4F ; distance low bit/count
