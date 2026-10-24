.setcpu "65816"
.segment "CODE"
.org $DC32
map_control_0edc32:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
