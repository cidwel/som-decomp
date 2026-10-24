.setcpu "65816"
.segment "CODE"
.org $4B09
map_control_0d4b09:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
