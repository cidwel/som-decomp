.setcpu "65816"
.segment "CODE"
.org $F27D
map_control_0cf27d:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
