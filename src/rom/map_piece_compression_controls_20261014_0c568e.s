.setcpu "65816"
.segment "CODE"
.org $568E
map_control_0c568e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
