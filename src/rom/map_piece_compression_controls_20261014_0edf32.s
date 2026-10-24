.setcpu "65816"
.segment "CODE"
.org $DF32
map_control_0edf32:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
