.setcpu "65816"
.segment "CODE"
.org $18CB
map_control_0c18cb:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
