.setcpu "65816"
.segment "CODE"
.org $4788
map_control_0c4788:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
