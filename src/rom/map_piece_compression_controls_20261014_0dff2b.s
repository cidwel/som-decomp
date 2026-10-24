.setcpu "65816"
.segment "CODE"
.org $FF2B
map_control_0dff2b:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
