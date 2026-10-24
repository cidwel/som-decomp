.setcpu "65816"
.segment "CODE"
.org $9819
map_control_0f9819:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
