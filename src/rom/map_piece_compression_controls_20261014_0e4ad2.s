.setcpu "65816"
.segment "CODE"
.org $4AD2
map_control_0e4ad2:
    .byte $EB ; backreference distance high bits
    .byte $9B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
