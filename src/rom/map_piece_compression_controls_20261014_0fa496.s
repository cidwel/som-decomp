.setcpu "65816"
.segment "CODE"
.org $A496
map_control_0fa496:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
