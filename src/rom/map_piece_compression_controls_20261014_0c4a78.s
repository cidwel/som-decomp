.setcpu "65816"
.segment "CODE"
.org $4A78
map_control_0c4a78:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
