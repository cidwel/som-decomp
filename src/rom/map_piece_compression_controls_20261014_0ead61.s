.setcpu "65816"
.segment "CODE"
.org $AD61
map_control_0ead61:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
