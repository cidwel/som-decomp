.setcpu "65816"
.segment "CODE"
.org $169A
map_control_0c169a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
