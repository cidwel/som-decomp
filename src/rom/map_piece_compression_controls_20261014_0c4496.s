.setcpu "65816"
.segment "CODE"
.org $4496
map_control_0c4496:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
