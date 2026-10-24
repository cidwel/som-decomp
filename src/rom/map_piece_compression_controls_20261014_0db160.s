.setcpu "65816"
.segment "CODE"
.org $B160
map_control_0db160:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
