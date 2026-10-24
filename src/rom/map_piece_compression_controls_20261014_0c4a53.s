.setcpu "65816"
.segment "CODE"
.org $4A53
map_control_0c4a53:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
