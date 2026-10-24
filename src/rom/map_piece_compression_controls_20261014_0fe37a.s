.setcpu "65816"
.segment "CODE"
.org $E37A
map_control_0fe37a:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
