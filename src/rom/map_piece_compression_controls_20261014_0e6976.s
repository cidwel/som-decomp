.setcpu "65816"
.segment "CODE"
.org $6976
map_control_0e6976:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
