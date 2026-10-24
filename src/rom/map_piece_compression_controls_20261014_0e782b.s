.setcpu "65816"
.segment "CODE"
.org $782B
map_control_0e782b:
    .byte $E0 ; previous-row copy escape
    .byte $DC ; row-distance/count
