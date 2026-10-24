.setcpu "65816"
.segment "CODE"
.org $F416
map_control_0ef416:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
