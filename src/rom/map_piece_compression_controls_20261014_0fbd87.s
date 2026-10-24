.setcpu "65816"
.segment "CODE"
.org $BD87
map_control_0fbd87:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
