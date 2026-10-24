.setcpu "65816"
.segment "CODE"
.org $AF47
map_control_0eaf47:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
